#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[100];
	char a;
	string q;
	long long n,z;//xia
	cin>>n;
	int aa[1000]={0};
	int m=0;
	while(n--){
		cin>>z>>a;
		s[m]=a;
		aa[m]=z;
		m++;//ge
	}
	int b=aa[0];
	int c=0;
	long long w=2;
	long long zong=1;	
	while(w<b){
		int g=0;
		for(int i=0;i<m;i++){
			if(aa[i]%w==0){
				g++;
			}
		}		
		if(g==m){
			for(int i=0;i<m;i++){
				aa[i]=aa[i]/w;	
			}
			zong=zong*w;
		}
		else{
			w++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<aa[i];j++){
			q=q+s[i];
		}
	}
	long long sum=0;
	long long x=q.size()-1;
		for(int i=0;i<q.size()/2;i++){
			if(q[i]!=q[x]){
				sum++;
			}
		x--;	
		}
		long long p=sum*zong;
	cout<<p;
return 0;
}
