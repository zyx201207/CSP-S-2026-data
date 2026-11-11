//100 pts
#include<bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
//看数据范围决定 long long , 记得备份文件(得部分分文件)
const int N=2e5+5;
struct node{
	int len;
	char c;
}a[N];
int main(){
	ios::sync_with_stdio(false);//Debug(调试)要关闭
	cin.tie(nullptr);cout.tie(nullptr);
	file("string");//不要注释 freopen,记得检查 freopen 文件名 
	long long n,m=0,s[N]={0},ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		m+=a[i].len;
		s[i]=s[i-1]+a[i].len;
		//for(int j=1;j<=a[i].len;j++) cout<<a[i].c;
	}
	long long mid=m/2+m%2,weizhi=0;
	for(int l=1,r=n;;){
		int midd=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<midd<<" "<<s[midd]<<endl;
		if(r-l==1){
			weizhi=r;
			break;
		}else if(s[midd]==mid){
			weizhi=midd;
			break;
		}else if(s[midd]>mid){
			r=midd;
		}else if(s[midd]<mid){
			l=midd;
		}
	}
	//cout<<mid<<" "<<weizhi<<" "<<a[weizhi].c;
	long long tmp1=mid-s[weizhi-1],tmp2=s[weizhi]-mid;
	char tmp3=a[weizhi].c,tmp4=a[weizhi].c;
	int weizhi1=weizhi,weizhi2=weizhi;
	if(m%2){
		tmp1=mid-s[weizhi-1]-1;
		if(tmp1==0){
			weizhi1--;
			tmp3=a[weizhi1].c;
			tmp1=a[weizhi1].len;
		}
		if(tmp2==0){
			weizhi2++;
			tmp4=a[weizhi2].c;
			tmp2=a[weizhi2].len;
		}
		while(weizhi1>=1&&weizhi2<=n){
			if(tmp1==tmp2){
				if(tmp3!=tmp4) ans+=tmp1;
				tmp1=0,tmp2=0;
			}else if(tmp1>tmp2){
				if(tmp3!=tmp4) ans+=tmp2;
				tmp1=tmp1-tmp2,tmp2=0;
			}else{
				if(tmp3!=tmp4) ans+=tmp1;
				tmp2=tmp2-tmp1,tmp1=0;
			}
			if(tmp1==0){
				weizhi1--;
				tmp3=a[weizhi1].c;
				tmp1=a[weizhi1].len;
			}
			if(tmp2==0){
				weizhi2++;
				tmp4=a[weizhi2].c;
				tmp2=a[weizhi2].len;
			}
			//cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<" "<<weizhi1<<" "<<weizhi2<<endl;
		}
	}else{
		if(tmp1==0){
			weizhi1--;
			tmp3=a[weizhi1].c;
			tmp1=a[weizhi1].len;
		}
		if(tmp2==0){
			weizhi2++;
			tmp4=a[weizhi2].c;
			tmp2=a[weizhi2].len;
		}
		while(weizhi1>=1&&weizhi2<=n){
			if(tmp1==tmp2){
				if(tmp3!=tmp4) ans+=tmp1;
				tmp1=0,tmp2=0;
			}else if(tmp1>tmp2){
				if(tmp3!=tmp4) ans+=tmp2;
				tmp1=tmp1-tmp2,tmp2=0;
			}else{
				if(tmp3!=tmp4) ans+=tmp1;
				tmp2=tmp2-tmp1,tmp1=0;
			}
			if(tmp1==0){
				weizhi1--;
				tmp3=a[weizhi1].c;
				tmp1=a[weizhi1].len;
			}
			if(tmp2==0){
				weizhi2++;
				tmp4=a[weizhi2].c;
				tmp2=a[weizhi2].len;
			}
			//cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<" "<<weizhi1<<" "<<weizhi2<<endl;
		}
	}
	cout<<ans;
	return 0;
}


