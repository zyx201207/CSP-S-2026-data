#include<bits/stdc++.h>
#define lpl long long
using namespace std;

const int N=2e5+5;
int n,A[N];
char C[N];
lpl ans=0,ansa=0;//ans:修改字符 ansa:总共字符

lpl min(lpl a,lpl b){
	if(a<=b)return a;
	else return b;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i]>>C[i];
		ansa += A[i];
	}
	lpl l_size = ansa / 2 , r_size = ansa / 2;//每一边需比对字符数量
	int l=0,r=n-1;
	int l_dang=0,r_dang=0;
	while(1){
		bool l_jia=false,r_jia=false;//有没有比尽 
		if(l_dang<=0)l_dang=min(l_size,A[l]),l_jia=true;
		if(r_dang<=0)r_dang=min(r_size,A[r]),r_jia=true;
		cout<<"dang:"<<l_dang<<" "<<r_dang<<"  zifu:"<<C[l]<<" "<<C[r];
		
		lpl jian=min(l_dang,r_dang);
		cout<<"  jian:"<<jian;
		
		if(l_jia)l_size-=l_dang,l++;
		if(r_jia)r_size-=r_dang,r--;
		cout<<"  size:"<<l_size<<" "<<r_size;
		
		if(C[l]!=C[r])ans+=jian;
		l_dang-=jian,r_dang-=jian;
		cout<<"  ans:"<<ans<<endl;
		
		if(l_size<=0&&r_size<=0)break;
	}
	cout<<ans;
	return 0;
}

