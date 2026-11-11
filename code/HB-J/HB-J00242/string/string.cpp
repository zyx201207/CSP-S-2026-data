#include<bits/stdc++.h>
using namespace std;
string t,t1,t2;
int cnt1,cnt2;
char c;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	int n,sum=0,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=sum;j<x+sum;j++)
			t[j]=c;
		sum+=x;
	}
	int s=1;
	while(t[s]!=0)s++;
	for(int i=0;i<s/2;i++)t1[i]=t[s-i];
	for(int i=0;i<=s/2;i++)t2[i]=t[i];
	for(int i=s/2-1;i<=s;i++)t2[i]=t[s-i];
	for(int i=s/2;i<=s;i++)t1[i]=t[i];
		
	for(int i=1;i<=s;i++){
		if(t1[i]!=t[i])cnt1++;
		if(t2[i]!=t[i])cnt2++;
	}
	cout<<min(cnt1,cnt2);
    return 0;
}

