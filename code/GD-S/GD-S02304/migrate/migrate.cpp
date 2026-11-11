#include <iostream>
#define ll long long

using namespace std;

const int N=1e6+5;

int c,t,n,L[N],R[N],f1[N],f2[N],cl[N],cr[N];
ll d,x[N],ans;

void work(){
	cin>>n>>d;
	for (int i=1;i<=n;i++)
		cin>>x[i];
	for (int i=1,r=1;i<=n;i++){
		while (r<n&&x[r+1]-x[i]<=d) r++;
		R[i]=r;
	}
	for (int i=n,l=n;i;i--){
		while (l>1&&x[i]-x[l-1]<=d) l--;
		L[i]=l;
	}
	ans=0;
	for (int i=1;i<=n;i++)
		f1[i]=f2[i]=cl[i]=cr[i]=0;
	// f1: 从前往后，唯一路径，至少走了一步到我这里的
	for (int i=1;i<=n;i++)
		if (R[i]>i)
			f1[R[i]]++;
	for (int i=1;i<=n;i++)
		if (L[R[i]]==i)
			f1[R[i]]+=f1[i];
	// f2: 从后往前，唯一路径，至少走了一步到我这里的
	for (int i=n;i;i--)
		if (L[i]<i)
			f2[L[i]]++;
	for (int i=n;i;i--)
		if (R[L[i]]==i)
			f2[L[i]]+=f2[i];
	for (int i=1;i<=n;i++)
		cl[L[i]]++,cr[R[i]]++;
	for (int i=1;i<=n;i++)
		if (R[i]-1>i)
			ans+=cl[R[i]-1]; // 无 无 
	for (int i=1;i<=n;i++)
		if (R[i]-1>i&&L[R[i]-1]==i)
			ans+=1ll*f1[i]*cl[R[i]-1]; // 有 无 
	for (int i=1;i<=n;i++)
		if (L[i]+1<i&&R[L[i]+1]==i)
			ans+=1ll*f2[i]*cr[L[i]+1]; // 无 有
	for (int i=1;i<=n;i++)
		if (R[i]>i&&R[R[i]]>R[i]&&L[L[R[R[i]]]]==i&&R[i]==L[R[R[i]]]+1)
			ans+=1ll*f1[i]*f2[R[R[i]]]; // 有 有 
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while (t--)
		work();
	return 0;
}
