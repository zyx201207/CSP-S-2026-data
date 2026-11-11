#include<bits/stdc++.h>
using namespace std;
char p[200010];
struct sjh{
	long long a;
	string c;
}s[200010];
long long  a1,sum;
int n,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;++i){
		cin>>a1>>p[i];
		if(p[i]==p[i-1]){
			s[k].a+=a1;
			s[k].c=p[i];
		}
		else{
			k++;
			s[k].a+=a1;
			s[k].c=p[i];
		}
	}
	if(k==1){
		cout<<"0";
		return 0;
	}
	long long l=1,r=k;
	while(l<r){
		if(s[l].c==s[r].c){
			long long temp1=s[r].a,temp2=s[l].a;
			s[l].a-=temp1;
			if(s[l].a<=0) l++;
			s[r].a-=temp2;
			if(s[r].a<=0) r--;
		}
		else{
			long long temp1=s[r].a,temp2=s[l].a;
			s[l].a-=temp1;
			if(s[l].a<=0) l++;
			s[r].a-=temp2;
			if(s[r].a<=0) r--;
			sum+=min(temp1,temp2);
		}
	}
	cout<<sum;
	
	return 0;
}
