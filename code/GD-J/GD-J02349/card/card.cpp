#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int b[m]={};
    cin>>n>>m;
    int s[n]={};
    int a[m]={};
    int num,ans;
    for(int d=1;d<=n;d++){
        for(int i=1;i<=m;i++){
            cin>>s[i];
        }
        for(int i=1;i<=n;i++){
            if(s[i]!=0){
            	for(int j=2;j<=n;j++){
                	if(s[i]==s[j]){
                    	s[i]=0;
                    	num=j;
                	}
            	}
        	}
            for(int i=1;i<=n;i++){
                if(s[i]!=0){
                    for(int j=1;j<=n;j++){
                        if(s[j]==0){
                            if(!(j<i<num)){
                                b[i]++;
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=ans;i++){
        cout<<b[i];
    }
    return 0;
}
