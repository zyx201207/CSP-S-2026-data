#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N  = 2e5 + 60;
int n , a[N];
char c[N];
int w[61] , m ,ans;
bool cmp(int x,int y){return x>y;}
void mj(int pe)
{
    if(pe <= 0)
        return ;
    int mw = 30 , cm = 0;
    for(int i=0;i<=30;i++)
    	w[i]=0;
    for(int i = 1;i <= n;i++)
 		for(int b=0;b<=30;b++)
            if((a[i]&(1ll<<b)))
                w[b]++;
		
    
//    for(int i=1;i<=n;i++)
//    {
//        if(!(a[i]&(1<<pe)))break;
//        for(int b=0;b<=min(mw,max(0,pe-1));b++)
//        {
//             if((a[i]&(1ll<<b)))
//                w[b]++,cm=max(cm,b);//2^b
//        }
//        mw = cm;
//    }
//    cout << pe << '\n';
//    for(int i = 1;i <= 5;i++)
//    	cout << w[i] << ' ' << i << '\n';
    for(int i=pe-1;i>=0;i--)
    {
        if(w[i] > m)
        {
            ans |= (1<<(i));
            mj(i);
            return ;
        }else if(w[i] == m)
        {
        	ans = (1ll<<30)-1;
            for(int j = 1;j <= n;j++)
                if((a[j]&(1ll<<i)))
                    ans &= a[j];
            cout << ans << '\n';
            exit(0);
        }
    }
    return ;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
    ans = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
 		for(int b=0;b<30;b++){
            if((a[i]&(1ll<<b)))
                w[b]++;//2^b
            //cout<<(1<<b)<<'\n';
		}
    }
    sort(a+1,a+n+1,cmp);
//    for(int i=0;i<=30;i++)
//	{
//		cout<<i<<' '<<w[i]<<'\n'; 
//	} 
    for(int i=30;i>=0;i--)
    {
        if(w[i] > m)
        {
        	//cout << i << '\n';
            ans |= (1<<(i));
            mj(i);
            break;
        }else if(w[i] == m)
        {
        	ans = (1<<30)-1;
            for(int j = 1;j <= n;j++)
                if((a[j]&(1ll<<i)))
                    ans &= a[j];
            cout << ans << '\n';
            return 0;
        }
    }
    cout << ans-1;
	return 0;
}

