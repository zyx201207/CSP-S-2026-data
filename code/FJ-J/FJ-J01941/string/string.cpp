#include<bits/stdc++.h>
using namespace std;
int n;
long num,sum=0,k=1;
char c;
char s[200000007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s[0]='t';
	for(int x=1;x<=n;x++){
		cin>>num>>c;
		int y=k;
		for(;y<=k+num-1;y++)//{
			s[y]=c;
			//cout<<c;
		//}
		k=y;
	}
	k--;
	for(int x=1;x<=k/2;x++){
		if(s[x]!=s[k-x+1])
			sum++;
		//cout<<sum;
	}
	cout<<sum<<endl;
	return 0;
}
