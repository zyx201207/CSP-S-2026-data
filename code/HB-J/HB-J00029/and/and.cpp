#include <bits/stdc++.h>
using namespace std;
int n,m;
long long arr[200010],ans;
bool flagA=true,flagB;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=17;i++){
		if((long long)pow(2,i)==n) flagB = true;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		long long x = arr[i];
		while(x){
			if(x%2==0) flagA = false;
			x /= 2;
		}
		if(arr[i]!=(i-1)) flagB = false;
	}
	sort(arr+1,arr+n+1);
	if(flagA){cout<<arr[n-m+1];return 0;}
	if(flagB){
		ans = arr[n];
		for(int i=n;i>=n-m+1;i--) ans = (ans&arr[i]);
		cout<<ans;return 0;}
	if(m==1){cout<<arr[n];return 0;}
	if(n<=2000&&m==2){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,(arr[i]&arr[j]));cout<<ans;return 0;}
	if(n<=2000&&m==n){
		ans = arr[n];
		for(int i=n;i>=1;i--) ans = (ans&arr[i]);
		cout<<ans;return 0;}
	if(n<=20){
		if(m==1){cout<<arr[n];return 0;}
		else if(m==2){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,(arr[i]&arr[j]));cout<<ans;return 0;}
		else if(m==3){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)ans=max(ans,(arr[i]&arr[j]&arr[k]));cout<<ans;return 0;}
		else if(m==4){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]));cout<<ans;return 0;}
		else if(m==5){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]));cout<<ans;return 0;}
		else if(m==6){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]));cout<<ans;return 0;}
		else if(m==7){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]));cout<<ans;return 0;}
		else if(m==8){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]));cout<<ans;return 0;}
		else if(m==9){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]));cout<<ans;return 0;}
		else if(m==10){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]));cout<<ans;return 0;}
		else if(m==11){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]));cout<<ans;return 0;}
		else if(m==12){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]));cout<<ans;return 0;}
		else if(m==13){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]));cout<<ans;return 0;}
		else if(m==14){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)for(int s=a+1;s<=n;s++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]&arr[s]));cout<<ans;return 0;}
		else if(m==15){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)for(int s=a+1;s<=n;s++)for(int d=s+1;d<=n;d++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]&arr[s]&arr[d]));cout<<ans;return 0;}
		else if(m==16){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)for(int s=a+1;s<=n;s++)for(int d=s+1;d<=n;d++)for(int f=d+1;f<=n;f++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]&arr[s]&arr[d]&arr[f]));cout<<ans;return 0;}
		else if(m==17){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)for(int s=a+1;s<=n;s++)for(int d=s+1;d<=n;d++)for(int f=d+1;f<=n;f++)for(int g=f+1;g<=n;g++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]&arr[s]&arr[d]&arr[f]&arr[g]));cout<<ans;return 0;}
		else if(m==18){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)for(int s=a+1;s<=n;s++)for(int d=s+1;d<=n;d++)for(int f=d+1;f<=n;f++)for(int g=f+1;g<=n;g++)for(int h=g+1;h<=n;h++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]&arr[s]&arr[d]&arr[f]&arr[g]&arr[h]));cout<<ans;return 0;}
		else if(m==19){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)for(int s=a+1;s<=n;s++)for(int d=s+1;d<=n;d++)for(int f=d+1;f<=n;f++)for(int g=f+1;g<=n;g++)for(int h=g+1;h<=n;h++)for(int z=h+1;z<=n;z++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]&arr[s]&arr[d]&arr[f]&arr[g]&arr[h]&arr[z]));cout<<ans;return 0;}
		else{for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)for(int q=k+1;q<=n;q++)for(int w=q+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;t++)for(int y=t+1;y<=n;y++)for(int u=y+1;u<=n;u++)for(int o=u+1;o<=n;o++)for(int p=o+1;p<=n;p++)for(int a=p+1;a<=n;a++)for(int s=a+1;s<=n;s++)for(int d=s+1;d<=n;d++)for(int f=d+1;f<=n;f++)for(int g=f+1;g<=n;g++)for(int h=g+1;h<=n;h++)for(int z=h+1;z<=n;z++)for(int x=z+1;x<=n;x++)ans=max(ans,(arr[i]&arr[j]&arr[k]&arr[q]&arr[w]&arr[e]&arr[r]&arr[t]&arr[y]&arr[u]&arr[o]&arr[p]&arr[a]&arr[s]&arr[d]&arr[f]&arr[g]&arr[h]&arr[z]&arr[x]));cout<<ans;return 0;}
	}
	ans = arr[n];
	for(int i=n;i>=n-m+1;i--){
		if((ans&arr[i])<arr[n-m+1]) continue;
		ans = (ans&arr[i]);
	}
	cout<<ans;
	return 0;}
