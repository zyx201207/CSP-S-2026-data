#include<bits/stdc++.h>
using namespace std;
int a[200001],s[200006][200006],far[200006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    for(int jk=1;jk<=t;jk++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=i;a[j]<=a[i]+d;j++){
                s[i][j]=j-1;
                far[i]=j;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                s[i][j]=s[i][far[i]]+s[far[i]][j];
                far[i]=j;
            }
        }
        int rp=0;
        for(int i=1;i<=n;i++){
            for(int J=i;J<=n;J++){
                for(int l=i;l<=n;l++){
                    if(J!=l&&s[i][l]==s[i][J]&&s[i][J]!=0)rp++;
                }
            }
        }
        cout<<rp;
    }
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
