#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,a[1000000];
	char c[1000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	queue<int>q;
	for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            q.push(c[i]);
        }
	}
	int cnt=0;
	while(!q.empty()){
        if(q.back()!=q.front())cnt++;
        q.pop()
	}
	cout<<cnt;
	return 0;
}
