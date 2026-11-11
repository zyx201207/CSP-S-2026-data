#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d,x[10005],s=0;
	for(int k=0;k<t;k++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
	}
	int w=0;
	for(int y=0;y<t;y++){
		for(int i=0;i<n;i++){
			int s=x[n-1]-x[i];
			if(s==d+1){
				w++;
			}
			else{
				x[n]=x[n-1];
			}
		}
		cout<<w<<endl;
	}
	
		
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

