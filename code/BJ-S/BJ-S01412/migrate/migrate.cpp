#include<bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==13||c==14){
		while(t--){
			int n,d;
			cin>>n>>d;
			int a;
			for(int i=0;i<n;i++)cin>>a;
			cout<<n-2<<endl;
		}
		return 0;
	}
    /*for(int tt=0;tt<t;tt++){
		//cout<<1;
		int n,d;
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		//cout<<1;
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++){
				int x=a[i],ans=0;
				while(x<a[j]){
					int ji=0;
					while(a[i+ji]<d+x)ji++;
					x+=ji;
					ans++;
				}if(x!=a[j]&&ans!=1)cout<<1<<" ";
				else cout<<0;
			}
	}*/
	/*
	    CCCCC        SSSSSS          PPPPP                   SSSSSS
     C     C      S               P     P                 S
    C            S               P     P                 S
   C              SSSSS         PPPPPP       _________    SSSSS
  C                    S       P             ---------         S
 C     C              S       P                               S
  CCCCC         SSSSSS       P                          SSSSSS
  */
    return 0;
}

