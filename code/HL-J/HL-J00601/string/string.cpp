#include <iostream>
#include <cstring>
using namespace std;

int a[200010];
char c[200010];
string s;


void solve() {
    int n;
    cin>>n;
    int L=0;
    int j=1;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        for (int k=j;k<=j+a[i];k++){
        	s[k]=c[i];
		}
		j+=a[i];
    }
    long long ans=0;
    for (int i=1;i<=j;i++) {
    	if (s[i]!=s[j-i+1]) ans++;
	}
    cout<<ans/2;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}

/*
#include <iostream>
#include <cstring>
using namespace std;

int a[200010],a1[200010];
char c[200010],c1[200010];
int qa[200010],ha[200010];
int qa1[200010],ha1[200010];


void solve() {
    int n;
    cin>>n;
    int L=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        qa[i]=qa[i-1]+a[i];
        L+=a[i];
    }
    for (int i=n;i>=1;i--) {
        ha[i]=ha[i+1]+a[i];
    }
    // merge
    int tn=n;
    for (int i=1,j=0;i<=n;i++) {
    	if (c[i]==c1[j]) {
    		a1[j]+=a[i];
    		tn--;
    		qa1[j]=qa1[j-1]+a1[j];
		}
		else{
			j++;
			a1[j]=a[i];
			c1[j]=c[i];
			qa1[j]=qa1[j-1]+a1[j];
		}
	}
	// update ha
	for (int i=tn;i>=1;i--) {
        ha1[i]=ha1[i+1]+a1[i];
    }
    
	// divide
	n=0;
	qa[0]=0;
    for (int l=0,r=tn+1;l<=tn;) {
    	if (qa[l+1]<=ha[r-1]) {
    		a[n]=qa1[l+1]-qa[n-1];
    		c[n]=c1[l+1];
    		l++;
    		qa[n]=qa[n-1]+a[n];
    		n++;
		}
		else{
			a[n]=ha1[r-1]-qa[n-1];
    		c[n]=c1[r-1];
    		r--;
    		qa[n]=qa[n-1]+a[n];
    		n++;
		}
	}
    
    cout<<n<<endl<<endl;
    
    for (int i=1;i<=n;i++) {
    	cout<<a[i]<<' '<<c[i]<<' '<<qa[i]<<endl;
	}
    
    int ans=0;
    for (int i=1;i<=n;i++){
    	if (c[i]!=c[n-i+1]){
    		ans+=a[i];
    		c[n-i+1]=a[i];
		}
	}
	cout<<ans;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}
*/ 
