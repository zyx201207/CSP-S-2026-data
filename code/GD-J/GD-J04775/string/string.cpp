#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum,res1,res2,i,j,last;
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	i=1;
	j=n;
	res1+=a[i];
	res2+=a[j];
	while(i<j){
		if(ch[i]!=ch[j]){
			sum+=min(res1,res2)-last;
		}
		if(res1<res2){
			last=res1;
			i++;
			res1+=a[i];
		}
		else if(res1>res2){
			last=res2;
			j--;
			res2+=a[j];
		}
		else{
			if(a[i+1]<a[j-1]){
				last=res1;
				i++;
				res1+=a[i];
			}
			else{
				last=res2;
				j--;
				res2+=a[j];
			}
		}
	}
	cout<<sum;
	return 0;
}
