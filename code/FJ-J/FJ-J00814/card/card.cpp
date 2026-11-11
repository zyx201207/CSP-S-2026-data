#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num[500005],flag[500005];
bool c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}else{
		for(int s=1;s<=n;s++){
			for(int i=s;i<=n;i++){
				if(flag[a[i]]!=0){
					for(int j=flag[a[i]];j<i;j++){
						a[j]=0;
						flag[a[j]]=0;
					}
				}
			}
			for(int i=s;i<=n;i++){
				if(a[i]!=0){
					num[a[i]]++;
				}
			}
		} 
		for(int i=1;i<=m;i++){
			if(i!=a[n]) cout<<num[i]-1<<" ";
			else cout<<n<<" ";
		}
	}
	 
	return 0;
} 
