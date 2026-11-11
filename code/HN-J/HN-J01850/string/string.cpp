#include<bits/stdc++.h>
using namespace std;
int n,j,t; 
string s;
long long sum;
int b[200001]={};
char b1[200001]={};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int r;
		string l;
		cin>>r;
		cin>>l;
		for(int i=1;i<=r;i++){
			s+=l;
		}
	}
	long long zj=0;
	zj=s.size()/2;
	int zzj=s.size()/2;
	if(s.size()%2==1){
		zzj++;
	} 
	for(long long i=0;i<zj;i++){
		if(s[i]==s[i+zzj-1]){
			continue;
		}else{
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
