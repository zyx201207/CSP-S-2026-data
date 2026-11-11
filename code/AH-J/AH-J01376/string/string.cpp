#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
char c[200010];
int pre[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        pre[i]=l;
    }
    if(l<1e9){
		string s="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		int cnt=0;
		for(int i=0;i<l;i++){
			if(s[i]!=s[l-i-1]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
    int cnt=0,flag=l%2,mid_class,mid_id;
    for(int i=1;i<=n;i++){
        cnt+=a[i];
        if((cnt>=l/2&&!flag)||(cnt>=(l+1)/2&&flag)){
            if(flag){
                mid_class=i;
                mid_id=(l+1)/2-(cnt-a[i]);
            }
            else{
                mid_class=i;
                mid_id=l/2-cnt+a[i];
            }
            break;
        }
    }
//    cout<<mid_class<<" "<<mid_id<<endl;
    if(!flag){
        int ans=0;
        for(int i=1;i<mid_class;i++){
            int u=upper_bound(pre+1,pre+1+n,l-pre[i])-pre;
            int x=pre[u]-l+pre[i],j=u+1;
            if(c[u]!=c[i]){
                if(x>a[i]){
                    ans+=(a[u]-x+a[i]);
                }else{
                    ans+=a[u];
                }
            }
            while(x<a[i]){
                x+=a[j];
                if(c[j]!=c[i]){
                    if(x>a[i]){
                        ans+=(a[j]-x+a[i]);
                    }else{
                        ans+=a[j];
                    }
                }
                j++;
            }
        }
        int x=a[mid_class]-mid_id,j=mid_class+1;
        while(x<mid_id){
            x+=a[j];
            if(c[j]!=c[mid_class]){
                if(x>mid_id){
                    ans+=(a[j]-x+mid_id);
                }else{
                    ans+=a[j];
                }
            }
            j++;
        }
        cout<<ans;
    }else{
        int ans=0;
        for(int i=1;i<mid_class;i++){
            int u=upper_bound(pre+1,pre+1+n,l-pre[i])-pre;
            //cout<<u<<" "<<l-pre[i]<<endl;
            int x=pre[u]-l+pre[i],j=u+1;
            if(c[u]!=c[i]){
                if(x>a[i]){
                    ans+=(a[u]-x+a[i]);
                }else{
                    ans+=x;
                }
            }
            while(x<a[i]){
                x+=a[j];
                if(c[j]!=c[mid_class]){
                    if(x>a[i]){
                        ans+=(a[j]-x+a[i]);
                    }else{
                        ans+=a[j];
                    }
                }
                j++;
            }
        }
        //mid_class
        int x=a[mid_class]-mid_id+1,j=mid_class+1;
        while(x<mid_id-1){
            x+=a[j];
            if(c[j]!=c[mid_class]){
                if(x>mid_id-1){
                    ans+=(a[j]-x+mid_id-1);
                }else{
                    ans+=a[j];
                }
            }
            j++;
        }
        cout<<ans<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
