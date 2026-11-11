#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int,int> cnts;
    bool L2_yh=true;
    int maxcnt=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]!=i+1) L2_yh=false;
        cnts[a[i]]+=1;
        maxcnt=max(maxcnt,cnts[a[i]]);
    }
    if(m==0){
        cout << maxcnt;
        return 0;
    }
    if(L2_yh){
        if(m==0){
            cout << 1;
            return 0;
        }
        int idx=0;
        while(m>=0){
            idx++;
            m-=idx;
        }
        cout << idx;
        return 0;
    }
    sort(a.begin(),a.end());
    if(maxcnt==1){
		int l=0,r=a.size()-1,ans=0;
		while(r-l>0){
			int idx=(l+r)/2;
			int mid=a[idx];
			int curcost=0;
			int i;
			bool fl=false;
			for(i=0;i<n;i++){
				if(a[i]>=mid){
					i--;
					break;
				}
				curcost+=mid-a[i];
				if(curcost>m){
					fl=true;
					i--;
					break;
				}
			}
			if(fl) r=mid-1;
			else l=mid+1;
			i++;
			ans=max(ans,cnts[mid]+i);
		}
		cout << ans;
		return 0;
	}
    int ans=0;
    for(int idx=(long long)a.size()-1;idx>=0;idx--){
        int mid=a[idx];
        int curcost=0;
        int i;
        for(i=0;i<n;i++){
            if(a[i]>=mid){
                i--;
                break;
            }
            curcost+=mid-a[i];
            if(curcost>m){
                i--;
                break;
            }
        }
        i++;
        ans=max(ans,cnts[mid]+i);
    }
    cout << ans;
    return 0;
}
