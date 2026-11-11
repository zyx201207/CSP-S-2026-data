#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],zai[500005],you[10000000],you2[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    
    bool abc=true;
    for(int i=2;i<=n;i++){
		if(a[i+1]!=a[i]){
			abc=false;
			break;
		}
	}
	if(abc){
		cout<<1;
		return 0;
	}
    int cnt=0,i=1;
    while(n--){
		for(int j=i;j<=n;j++){
			bool flag =false;
			for(int k=1;k<=cnt;k++){
				if(zai[k]==a[j]){
					flag=true;
				    break;
			     }
		    }
		    if(!flag){
				cnt++;
				a[cnt]=a[j];
			}else{
				int cnt1=0;
				bool flag1=true;
				for(int k=1;k<=cnt;k++){
					if(flag==false){
						zai[k]=0;
						cnt1++;
					}else if(zai[k]==a[j]){
						if(flag1==true){
							flag1=false;
						}else{
							zai[k]=0;
							cnt1++;
						}
					}
				}
				cnt-=cnt1;
			}
		 }
		 for(int j=1;j<=cnt;j++){
			  you[zai[j]]=1;
		 }
		 for(int j=1;j<=m;j++){
			  you2[j]+=you[j];
		 }
		i++;
	}
	
	for(int p=1;p<=m;p++){
		cout<<you2[p]<<" ";
	}
    return 0;
}
