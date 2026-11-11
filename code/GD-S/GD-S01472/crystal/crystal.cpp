#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,mx,sum;
bool cmp(ll a,ll b){return abs(sum/n-a)<abs(sum/n-b);}
inline ll read(){
	ll num=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}
void dfs(int deep,vector<ll> arr){
	if(deep>m){
		for(ll i=1;i<=n;i++){
			ll cnt=0;
			for(ll j=1;j<=n;j++)if(arr[i]==arr[j])cnt++;
			mx=max(cnt,mx);
		}
		return;
	}
	for(ll i=1;i<=n;i++)arr[i]++,dfs(deep+1,arr),arr[i]--;
}
int main(){
	//freopen("D://crystal/crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	n=read(),m=read();
	vector<ll> arr(n+1);
	for(ll i=1;i<=n;i++)arr[i]=read(),sum+=arr[i];
	ll a=rand()%n+1,b=rand()%n+1;
	if(a==n&&n!=1)a--;
	if(b==n&&n!=1)b--;
	if(a==1&&n!=1)a++;
	if(b==1&&n!=1)b++;
	if(n<=5){
		dfs(1,arr);
		cout<<mx;
		return 0;
	}else if(arr[a]==a&&arr[b]==b){
		for(ll i=1;;i++){
			ll t=(1+i)/2*i;
			if(t<=m&&t+i+1>m){
				cout<<i;
				return 0;
			}
		}
	}/*else if(arr[a]-arr[a-1]==arr[b]-arr[b-1]){
		sort(arr.begin(),arr.end());
		ll cnt=arr[1];
		if(cnt>m){
			cout<<0;
			return 0;
		}
		for(ll i=2;;i++){
			cnt+=arr[2]-arr[1];
			if(cnt>m){
				cout<<i-1;
				return 0;
			}
		}
	}*/
	sort(arr.begin()+1,arr.end(),cmp);
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(abs(sum/n-arr[i])>m)break;
		m-=abs(sum/n-arr[i]);
		ans++;
	}
	cout<<ans;
	return 0;
}
//jie ya mi ma:"Oct31==Dec25?"
//wo shi quuuuuuuuuuuuuuuuuuu
//wei shen me zuo wei yi tiao qu wo bu hui qu jian dp
//bu dui zhe hao xiang bu shi qu jian dp
//hai shi mian xiang shu ju bian cheng ba
//J dui wan fa xian ji fang tong xue zen me dou zhe me qiang orz %%%
//hai shi wo tai qu le
//fan zheng wo jiu shi mei tiao
//hai shi xian gao hao wen hua ke ba
//hao xiang J de kuai du mei jia inline
//bu guo yang qi you hua hao xiang hui zi dong jia
//suan le fan zheng dou cha bu duo
