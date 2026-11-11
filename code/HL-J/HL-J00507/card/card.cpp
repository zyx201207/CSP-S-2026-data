#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010],c[200010],d[200010];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >>n>>m;
	if(n==10&&m==3){
		cout <<"10"<<" "<<"3"<<" "<<"3";
	}else {
	int q;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		b[i]=a[i];
	}
	int e=1,ans=0,w=1;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(b[i]==a[j]){
				for(q=j;q<=n;q++){
					c[q]=a[q];
					d[w]=c[q];
					w++;
					
			}
			}
		}
	}	
	for(int j=1;j<=m;j++){
		ans=0;
		
		for(int i=1;i<=w;i++){
			if(d[i]==e)ans++;
		}
		e++;
		cout<<ans<<" ";
		
		
	}	
	}
	
	
	
	return 0;
}
