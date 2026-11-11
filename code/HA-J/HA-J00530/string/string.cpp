#include<bits/stdc++.h>
using namespace std;
int x[100050];
string l[100050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	long long sum=0,sun=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>l[i];
	}
	string num=l[1];
	for(int i=1;i<=n;i++){
		if(num==l[i])a=1;
		else a=-1;
	}
	if(a==1){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(l[i]==l[1])sum+=x[i];
		else{
			sun+=x[i];
		}
	}
	if(sum<=sun){
		cout<<sum<<endl;
	}
	else{
		cout<<sun<<endl;;
	}
	cout<<sun<<endl;
	return 0;
}
