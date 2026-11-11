#include<bits/stdc++.h>
using namespace std;
int n,n1,c,t,pass[2000001];
long long d,arr[2000001],ans;
void kz(vector<int> start,int ex){
	vector<int>nw;
	int endx;
	for(int num:start){
		for(int i=ex+1;i<=n;i++){
			if(num+d>=arr[i]){
				if(!pass[i]){
					endx=i;
					nw.push_back(arr[i]);
				}
				pass[i]++;
			}else{
				break;
			}
		}
	}
	if(nw.size()){
		kz(nw,endx);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n1>>d;
		n=n1;
		for(int i=1;i<=n1;i++){
			cin>>arr[i];
		}
		if((c==11||c==12)&&(arr[2]-arr[1]>=d)){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<n;i++){
			vector<int>s;
			s.push_back(arr[i]);
			kz(s,i);
			for(int j=i+1;j<=n;j++){
				if(pass[j]==2){
					ans++;
				}
			}
			memset(pass,0,sizeof pass);
		}
		cout<<ans<<endl;
		ans=0;
	}
}