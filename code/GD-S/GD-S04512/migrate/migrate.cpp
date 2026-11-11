#include <bits/stdc++.h>
using namespace std;

//freopen("migrate.in","r",stdin);
//feropen("migrate.out","w",stdout);

int main(){
	int c,t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int a[n+1];
		cin>>a[1];
		vector<int>s;
		d.push_back(1);
		int b[n+1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			
			b[i]=a[i]-a[i-1];
			if(b[i]>d){
				s.push_back(i);
			}
		}
		for(int i=0;i<=d.size();i++){
			for(int j=a[s[i]];j<a[s[i+1]];j++){
				int end=a[s[i+1]-1];
				int sum=0;
				ji=0;
				for(int k=j+1;k<a[s[i+1]];k++){
					
					if(sum+a[k]<d){
						sum=sum+a[k];
						continue;
					}
					else{
						sum=0;
						ji++;
					}
					
				}
				int start=j;
				int sum=0;
				ji2=0;
				for(int k=end;k>=a[j];k--){
					
					if(sum+a[k]<d){
						sum=sum+a[k];
						continue;
					}
					else{
						sum=0;
						ji++;
					}
					
				}
					
				}
			}
		} 
		
		
	}
}
