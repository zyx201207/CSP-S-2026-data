#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	string s="";
	cin >> n;
	if(n==1) {
		int a;
		char c;
		cin>>a>>c;
		cout<<"0";
		return 0;
	}
	long long a[n]={0};
	char c[n];
	for(int i=0;i<n;i++)
		cin>>a[i]>>c[i];
	if(n==2 && c[0]==c[1]) 
		cout<<"0";
	else {
		long long x=0;
		bool b=true;
		for(int i=0;i<n/2;i++)
			if(a[i]!=a[n-1-i])
				b=false;
		if(b){
			for(int i=0;i<n/2;i++)
				if(a[i]==a[n-1-i])
					if(c[i]!=c[n-i-1])
						x+=a[n-1-i];
		}
		else{
			int i=0, j=n-1;
			while(i!=j){
				long long in=min(a[i],a[j]);
				a[i]-=in;
				a[j]-=in;
				if(c[i]!=c[j])
					x+=in;
				if(a[i]==0)
					i++;
				if(a[j]==0)
					j--;
			}
		}
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
