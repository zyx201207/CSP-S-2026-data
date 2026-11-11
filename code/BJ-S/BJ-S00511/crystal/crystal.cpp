#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,c=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(m-(a[i]-a[j])>=0){
                m=m-(a[i]-a[j]);
                c++;
            }else{
                ans=max(ans,c);
                break;
            }
        }
    }
    cout<<ans;
    //I AK CSP!
    ;;;;;             ;;;         ;;     ;;            ;;;;;;        ;;;;;;;;      ;; ;;;;;        ;;;
     ;;;             ;; ;;        ;;    ;;           ;;      ;;    ;;              ;;;    ;;       ;;;
     ;;;            ;;   ;;       ;;   ;;          ;;             ;;               ;;      ;;      ;;;
     ;;;           ;;     ;;      ;;  ;;         ;;                ;;              ;;;    ;;       ;;;
     ;;;          ;;;;;;;;;;;     ;;;;;          ;;                  ;;;;;;;       ;; ;;;;;        ;;;
     ;;;         ;;         ;;    ;;  ;;         ;;                         ;;     ;;              ;;;
     ;;;        ;;           ;;   ;;   ;;          ;;                        ;;    ;;
     ;;;       ;;             ;;  ;;    ;;           ;;      ;;             ;;     ;;
    ;;;;;     ;;               ;; ;;     ;;            ;;;;;;       ;;;;;;;;       ;;              ;;;
}

