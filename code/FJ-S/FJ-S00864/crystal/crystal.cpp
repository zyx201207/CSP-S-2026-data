#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,s;
	cin>>a>>s;
	long long d[a];
	for(long long i=0;i<a;i++){
		cin>>d[i];
	}
	sort(d,d+a);
	int n=0;
	while(true){
		for(int i=0;i<a;i++){
			if(d[i]!=d[0] && s>=i*(d[i]-d[0])){
				for(int z=0;z<i;z++){
					d[z]=d[i];
					s-=d[i]-d[z];
				}
			}
			if(s<(i+1)*(d[i+1]-d[0])){
				n=1;
				break;
			}
		}
		if(n==1) break;
	}
	long long q=1,w=0;
	for(int i=1;i<a;i++){
		if(d[i]==d[i-1]) q++;
		else{
			w=max(q,w);
			q=1;
		}
		if(i==a-1) w=max(q,w);
	}
	cout<<w;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
