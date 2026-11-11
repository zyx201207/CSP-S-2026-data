#include<bits/stdc++.h>
using namespace std;
long long n[200005]={0};
long long a=0,b=0,c=0,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>n[i];
		
	}
	if(b==1){
		for(int i=1;i<=a;i++){
		    ans=max(b,n[i]);
	}
	cout<<ans;
	return 0;
	}if(b==2){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				 ans=max(ans,(n[i]&n[j]));
		}}
		cout<<ans;
		return 0;
	}if(a==b){
		ans=n[1];
		for(int i=2;i<=a;i++){
			ans=ans&n[i];
		}
		cout<<ans;
		return 0;
	}if(b==3){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int l=j+1;l<=a;l++){
					ans=max(ans,(n[i]&n[j])&n[l]);
				}
				 
		}}
		cout<<ans;
		return 0;
	}if(b==4){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int l=j+1;l<=a;l++){
					for(int k=l+1;k<=a;k++){
					ans=max(ans,(n[i]&n[j])&n[l]&n[k]);
				}
				}
				
				 
		}}
		cout<<ans;
		return 0;
	}if(b==5){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int l=j+1;l<=a;l++){
					for(int k=l+1;k<=a;k++){
						for(int x=k+1;x<=a;x++){
							ans=max(ans,(n[i]&n[j])&n[l]&n[k]&n[x]);
						}
					
				}
				}
				
				 
		}}
		cout<<ans;
		return 0;
	}else{
		cout<<1;
	}
}
