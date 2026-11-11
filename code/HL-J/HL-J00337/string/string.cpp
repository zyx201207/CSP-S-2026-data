#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long cnt;
struct Node{
	char zm;
	long long sum;
}node[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>node[i].sum>>node[i].zm; 
	} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=node[i].sum;j++){
					s+=node[i].zm;
			}
		}
		long long j=s.size()-1;
		long long i=0;
		while(i<=j)
		{
			if(s[i]!=s[j])
			{
				cnt++;
				j--;
				i++;
			 } else {
			 	i++;
			 	j--;
			 } 
		}
	cout<<cnt;
	return 0;
}
