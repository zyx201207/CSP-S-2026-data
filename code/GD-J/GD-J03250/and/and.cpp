#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[20005];
int main(){
	//优化ll数组 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//打开文件 
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	//输入 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}ll mb=0,ans=0;
	ll k=n-1;
	//特殊情况：m为1 
	if(m==1){
		for(int i=1;i<=n;i++){
			if(mb<a[i]){
				mb=a[i];
				ans=i;
			} 
		}cout<<a[ans];
		return 0; 
	}
	//特殊情况：m为2 
	else if(m==2){
		ll p=0;
		for(int i=1;i<=n-1;i++){
			p=a[i];
			for(int j=1;j<=k;j++){
				p=p&a[i+j];
				if(p>mb){
					mb=p;
					ans=i+j;
				}
			}k-=1;
		}cout<<a[ans];
		return 0; 
	}
	//特殊情况：m=n
	else if(m==n){
		cout<<n;
	} 
	//特殊情况：m=n-1
	else if(m==n-1){
		ll t=1;
		ll p=0,o=0;
		for(int j=1;j<=n;j++){
			if(j==1){
				p=a[2];
			}else{
				p=a[1];
			}
			for(int i=1;i<=n;i++){
				if(i!=j){
					p=p&a[j];
				}else{
					continue;
				} 
			}if(mb<p){
				mb=p;
				ans=n;
				o=j;
			}
		}if(o==ans){
			cout<<a[n-1];
		}else{
			cout<<a[n];
		}
		 
	}
	
	//其他情况
	
	//关闭文件 
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
