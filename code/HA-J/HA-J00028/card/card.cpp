#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[3200];
int b[300001];
bool c[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
    	for(int j=0;i<n;j++){
    		for(int k=j+1;k<n;k++){
    			if(a[j]==a[k]){
    				j=k;
    				cnt=j;
    			}
    		}
    	}
    	for(int j=cnt;j<n;j++){
    		if(c[a[j]]==false){
    			b[a[j]]++;
    			c[a[j]]=true;
    		}
    	}
    }
    for(int i=0;i<m;i++){
    	cout<<b[i];
    }
	return 0;
}
