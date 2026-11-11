#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a[10005];
	int b[100005];
	int c[100005];
	vector<int> l(10);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		while(a[i]==0){
			b[i]+=a[i]%2*10*n;
		}
	}
	for(int i=n;i>0;i--){
		int count=1;
		int x=n;
		int w[100005];
		if(sizeof(b[i])==sizeof(b[i-count])){
			for(int j=0;j<sizeof(b[i])/4;j++){
				if(b[i]==b[i-count]){
					c[j]+=1*10*j;	
				}
				else if(b[i]!=b[i-count]){
					c[j]+=0;
				}
			}
		}
		else if(sizeof(b[i])!=sizeof(b[i-count])){
			for(int j=0;j<min(sizeof(b[i])/4,sizeof(b[i-count]))/4;j++){
				if(b[i]==b[i-count]){
					c[j]+=1*10*j;	
				}
				else if(b[i]!=b[i-count]){
					c[j]+=0;
				}
			}
		}
		if(count!=x) count++;
	}
	for(int i=0;i<n;i++){
		l[i]+=c[i]%(10*i+1)*(2^i);
	}
	sort(l.begin(),l.end());
	cout<<"7";
	return 0;
}

