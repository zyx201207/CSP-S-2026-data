#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		int y=0;
		for(int j=0;j<n;j++){
			cin>>a[j];
			for(int x=j;x<n;x++){
				if(a[x]-a[j]<=d){
					int b=a[x]-a[j];
					if(b==x-1) y++;
				}
			}
		}
		cout<<y<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
