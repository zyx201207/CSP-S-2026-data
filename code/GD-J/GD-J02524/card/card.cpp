#include<bits/stdc++.h>
using namespace std;
int q[1000000];
int main(){
   freopen("and.in ","r",stdin);
  freopen("and.out ","w",stdout);
    long long a,b;
	cin>>a>>b;
	int f[100000];
	for(int i=1;i<=a;i++)cin>>f[i];
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			for(int d=i;d<j;d++){
				if(f[j]==f[d])f[j]=0;
		    }
		    	for(int j=a;j>=i;j--){
			q[f[j]]++;
			if(f[j]==0)break;
		}
		}
	
	}
	sort(f+1,f+n+1);
	for(int i=1;i<=b;i++)cout<<q[i]-1<<" ";
    return 0;
}

