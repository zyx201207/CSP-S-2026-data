#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q,num; cin>>c>>n>>m>>d>>q;
	long long mp[m];
	long long mp_1[n];
	for(int i=1;i<=m;i++){
		cin>>mp[i];
	}
	for(int j=1;j<=d;j++){
		cin>>mp_1[j];
	}

	long long cnt = c+n+m+d+q;
	if(cnt%2==0){
		cnt+=3;
	}else{
		cnt+=3;
	}
	cout<<cnt<<endl;
	cout<<num<<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
