#include<bits/stdc++.h>
using namespace std;
int n,m,flag,cnt,ans,tmp;
const int N=5e5+3;
int a[N];
int s[N];
int dp[N];//·Ö 

void finddp(){
	for(int i=1;i<=n;i++){
		if(s[i]>=s[i-1]){
			dp[i]=cnt;
			cnt++;
		}
		else if(i==n) dp[n]=dp[n-1]+1;	
		else{
			cnt=1;
			dp[i]=cnt;
			cnt++;
		}
	}
}

void fib(){
	for(int i=1;i<=n;i++){
			if(dp[i]<dp[i+1]||(s[i+1]==0&& i!=n-1)){
				tmp+=s[i]*cnt;
				cout<<tmp<<" ";
				if(tmp<=m) ans=max(cnt,ans);
				cnt++;
			}
			
			else{
				tmp=0;cnt=1;
			}
		}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) flag++;
	} 
	//A
	if(flag==n-1){
		cout<<n<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	flag=0;
	sort(a+1,a+n+1);
	a[n+1]=a[n];
	//B
	for(int i=1;i<=n;i++){
		if(a[i-1]-a[i-2]==a[i]-a[i-1]) flag++;
		if(i<=n)
			s[i]=a[i+1]-a[i];
	}
	s[n]=0;
	if(flag==n-2){
		cout<<m/(a[2]-a[1])<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	
	cnt=1;
	finddp();
	
	tmp=0,cnt=1;
	fib();
	cout<<endl;
	cout<<ans+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
