//14:30~16:01
//I borrow a apartment in a street where you live
//To meet you by accident
//In the three years of high middle-school
//Why not me read books carefully
//I have not enter the school that is the same as yours
//I find a job
//It`s close from your apartment
//When I start to learn to do pies
//I just found that
//You don`t eat lunch
//You pass me by my shoulder once again
//What are you listening in your headphone
//Can you tell me
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500009],c[500009];
set<int> s;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	c[i]=a[i]-a[i-1];
	}
    for(int i=1;i<=n;i++){
    	if(c[i]==0) continue;
		else s.insert(c[i]);
	}
	cout<<s.size();
	return 0;
}