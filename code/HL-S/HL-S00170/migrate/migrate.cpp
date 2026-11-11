#include<iostream>
#include<utility>
long long arr[2000001];
int c;
std::pair<int,int>ltrf(int l,int r,long long d){
	int a1=-1,a2=l;
	for(int i=l+1;i<=r;i++){
		if(arr[i]-arr[a2]>d){
			a2=i-1;
			if(a1==-1){a1=i-1;
			}
		}
	}
	return(std::make_pair(a1,a2));}
std::pair<int,int>rtlf(int l,int r,long long d){
	int a1=-1,a2=r;
	for(int i=r-1;i>=l;i--){
		if(arr[a2]-arr[i]>d){
			a2=i+1;
			if(a1==-1){a1=i+1;
			}
		}
	}
	return(std::make_pair(a1,a2));}
void solve(){
	int n;long long d;
	std::cin>>n>>d;
	long long ans=0;
	for(int i=1;i<=n;i++){std::cin>>arr[i];}
	if(c==11||c==12){
		if(arr[2]-arr[1]>=d){std::cout<<"0\n";return;}
	}if(c==13||c==14){
		int l=1;
		while(arr[l+1]-arr[1]<=d)l++;
		int r=n;
		while(arr[n]-arr[r-1]<=d)r--;
		if(l-r==1){std::cout<<"1\n";}
		else{std::cout<<"0\n";}return;
	}
	for(int l=1;l<n;l++){
		for(int r=l+1;r<=n;r++){
			if(arr[r]-arr[l]>d){
				std::pair<int,int>p1=ltrf(l,r,d),p2=rtlf(l,r,d);
				if(p1.first-p2.second==1&&p1.second-p2.first==1){
					ans++;
				}
			}
		}
	}
	std::cout<<ans<<"\n";
return;}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
	int t;std::cin>>c>>t;
	while(t--){
		solve();
	}
return 0;}
