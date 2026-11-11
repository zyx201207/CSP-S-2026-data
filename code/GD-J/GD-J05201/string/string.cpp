#include<bits\stdc++.h>
using namespace std;
char b[200005];
long long i,j,k,n,m,s,a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=1,j=n;i<j;){
		if(a[i]<=0)
		i++;
		if(a[j]<=0)
		j--;
		if(i>=j)
		break;
		if(b[i]!=b[j])
		s++;
		a[i]--;a[j]--;
}
cout<<s;
}
