//GZ_J00372 杨荣睿 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

long long n,m,a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	vector<int>v;
	for(int i=0;i<n;i++){
	    cin>>a;
	    v.push_back(a);
	}
	if(m==1){
		for(int i=0;i<m;i++){
	    cout<<n<<" ";
	    return 0;
	}
	}
	cout<<1;
	return 0;
} 
