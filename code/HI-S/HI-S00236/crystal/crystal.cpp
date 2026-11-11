#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[500005]={0};
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int t=s[i];
			int b=0;
			if(t<s[j]){
				b=s[j];
				s[i]=b;
				s[j]=t;
			}
		}
	}
	int h=1;
	for(int i=n-1;i>=0;i--){
		if(s[i-1]-s[i]>m){
			if(s[i]==s[i-1]){
					h++;
				}
			break;
		} 
		for(int j=0;j<m;j++){
			if(m==0){
				if(s[i]==s[i-1]){
					h++;
				}
				break;
			}
			if(s[i]==s[i-1]){
				break;
			}
			s[i]++;
			m-=h;
			
		}

		if(s[i]==s[i-1]){
			h++;
		}
	}
	cout<<h;
	return 0;
}
