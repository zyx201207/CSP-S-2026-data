//GZ-J00526 袁金厚 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,num[300050],seat[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	vector<long long>q;
	for(long long i=0;i<n;i++){
		long long x;
		cin>>x;
	    q.push_back(x);
		num[q[i]]=i+1;	
	}
	for(long long i=0;i<q.size();i++){
		if(seat[q[i]]==0){
		cout<<num[q[i]]<<" ";
		seat[q[i]]++;
		}
	}
	return 0;
} 
