#include<bits/stdc++.h>
using namespace std; 
    long long n,m;
	long long a[10000005];//手牌 
	long long b[10000005];//牌桌 
	long long c[10000005];//计数器
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
	}
	for(int pp=1;pp<=n;pp++){//局数 
			for(int i=pp;i<=n;i++){//手牌 
				for(int j=1;j<i;j++){//判断相同 
					if(b[j]==a[i]){
						for(int k=j;k<i;k++){//归零 
							b[k]=0;
						}
						break;
					}
				}
				b[i]=a[i];
	}
	for(int j=1;j<=n;j++){
		if(b[j]!=0){
			c[b[j]]++;
		}
	}
	for(int j=1;j<=n;j++){
		b[j]=0;
	}	
}

	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
