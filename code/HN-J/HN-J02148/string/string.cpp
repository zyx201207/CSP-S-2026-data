#include<bits/stdc++.h>
using namespace std;
int a[10005];
char b[10005];
char s[10005];
int w=0;
int ans;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
	}
	a[0]=0;
	for(int i=1;i<=n;i++){
		w+=a[i];
		for(int j=w-a[i]+1;j<=w;j++){
			s[j]=b[i];
		}
	}
	for(int i=1;i<=w;i++){
		cout<<s[i]<<" ";
	}
	if(w%2==0){
		for(int i=1;i<=w/2;i++){
			for(int j=w/2+1;j<=w;j++){
				if(s[i]!=s[j]){
					ans++;
				}
			}
		}
	}
	else{
		for(int i=1;i<=(w-1)/2;i++){
			for(int j=(w+1)/2+1;j<=w;j++){
				if(s[i]!=s[j]){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

