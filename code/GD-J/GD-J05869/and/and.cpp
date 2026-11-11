#include<bits/stdc++.h>
using namespace std;
long long num,goal,a[200005],maxx,b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>num>>goal;
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
	sort(a,a+num);
	for(int i=num-1;i>=num-goal;i--){
		b[num-1-i]=a[i];
	}
	maxx=b[0];
	for(int i=1;i<goal;i++){
		maxx=maxx&b[i];
	}
	cout<<maxx;
	return 0;
}

