#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int>v;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			v.push_back(a[j]);
			int si=v.size();
			for(int k=0;k<si;k++){
				if(a[k]==a[j]){
					for(int l=k;l<j;l++){
						v.erase(l);
				    }
				}
			}
	    }
	    cout<<v.size()<<" ";
	}
    return 0;	
}


