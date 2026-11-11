#include<bits/stdc++.h>
using namespace std;

string s;
long long sum=0;
long long m;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	long long lens=0;
	for(long long i=1;i<=n;i++){
		
		char a;
		cin>>m;
		cin>>a;
		for(long long j=lens+1;j<=lens+m;j++){
			s[j]=a;
		}lens+=m;
	}
	int f=1;
	for(long long i=1;i<=lens/2;i++){
		if(s[i]!=s[lens-i+1]){
			f=0;
			sum++;
		}
	}
	if(f==1){
		cout<<0;
	}else{
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
