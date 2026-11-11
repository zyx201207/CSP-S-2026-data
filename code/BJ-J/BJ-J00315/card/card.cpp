#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int t[300005];
int ak[300005];
void kkk(int x){
	memset(ak,0,sizeof(ak));
	int iii=x;
	for(int i=x;i<=n;i++){
		bool flag=false;
		for(int k=1;k<=iii;k++){
			if(flag){
				ak[k]=0;
			}
			if(ak[k]==a[i]){
				iii=k;
				flag=true;
			}
		}
		ak[iii]=a[i];
		iii++;
		
	}
	iii--;
	for(int i=1;i<=iii;j++){
		t[ak[i]]++;
	}
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    	kkk(i);
    }
    for(int i=1;i<=m;i++){
    	cout<<t[i]<<" ";
    }
    return 0;
}