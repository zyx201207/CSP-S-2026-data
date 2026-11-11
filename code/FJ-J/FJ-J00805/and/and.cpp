#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
long long n,m,a,aa[N],ans;
long long t_ans,id[N],num=0,shu[N];
struct aaa{
	int maxx[105],cnt=0;
}b[N];
long long f(int k,int temp){//最多100次，不会爆栈 
	int num1=0;
	int id1[N]={},shu1[N]={};
	long long temp_ans;
	for(int j=1;j<=temp;j++){
		if(b[id[j]].maxx[k]==1){
			num1++;
			shu1[num1]=aa[id[j]];
			id1[num1]=id[j];
		}
	}
	if(num1>=m){
		for(int i=1;i<=num1;i++){
			id[i]=id1[i];
			shu[i]=shu1[i];
			if(i==1) temp_ans=shu[i];
			else temp_ans&=shu[i];
		}
	}else{
		num1=temp;
	}
	if(num1==m){
		return temp_ans;
	}else if(k==100){
		for(int i=1;i<=num;i++){
			if(i==1) temp_ans=aa[id[i]];
			else if(i==m+1) break;
			else temp_ans&=aa[id[i]];
		}
		return temp_ans;
	}else{
		return f(k+1,num1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a;
		aa[i]=a;
		int temp=1;
		while(1)
			if(a>=temp)
				temp*=2;
			else
				break;
		temp/=2;
		while(1){
			if(temp==0) break;
			b[i].cnt++;
			if(a>=temp){
				a-=temp;
				b[i].maxx[b[i].cnt]=1;
			}else{
				b[i].maxx[b[i].cnt]=0;
			}
			temp/=2;
		}
		for(int j=b[i].cnt,k=1;j>=1;j--,k++){
			swap(b[i].maxx[j],b[i].maxx[100-k+1]);
		}
	}
	for(int i=1;i<=100;i++){//复杂度为O(100*n) 
		num=0;
		long long t_ans;
		memset(id,0,sizeof(id));
		memset(shu,0,sizeof(shu));
		for(int j=1;j<=n;j++){
			if(b[j].maxx[i]==1){
				shu[++num]=aa[j];
				id[num]=j;
				if(num==1) t_ans=shu[num];
				else t_ans&=shu[num];
			}
		}
		if(num>m){
			ans=f(i+1,num);
			break;
		}else if(num==m){
			ans=t_ans;
			break;
		}
	}
	cout << ans;
	return 0;
} 
/*
4 2
3 15 12 12
*/
