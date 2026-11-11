#include<bits/stdc++.h>
using namespace std;
int a[2000010];
char c[2000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        k+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    if(k%2==0){
        int ans=0;
        string l1="",r="",l="";
        for(int i=0;i<s.size()/2;i++){
            l1+=s[i];
        }
        for(int i=s.size()/2;i<s.size();i++){
            r+=s[i];
        }
        for(int i=l1.size()-1;i>=0;i--){
            l+=l1[i];
        }
        for(int i=0;i<l.size();i++){
            if(l[i]!=r[i])ans++;
        }
        cout<<ans;
    }else{
        int ans=0;
        string l1="",r="",l="";
        for(int i=0;i<s.size()/2;i++){
            l1+=s[i];
        }
        for(int i=s.size()/2+1;i<s.size();i++){
            r+=s[i];
        }
        for(int i=l1.size()-1;i>=0;i--){
            l+=l1[i];
        }
        for(int i=0;i<l.size();i++){
            if(l[i]!=r[i])ans++;
        }
        cout<<ans;
    }
    //I AK IOI
    ;;;;;             ;;;            ;;     ;;       ;;;;;        ;;;;;;        ;;;;;      ;;;
     ;;;             ;; ;;           ;;    ;;         ;;;       ;;      ;;       ;;;       ;;;
     ;;;            ;;   ;;          ;;   ;;          ;;;     ;;          ;;     ;;;       ;;;
     ;;;           ;;     ;;         ;;  ;;           ;;;    ;;            ;;    ;;;       ;;;
     ;;;          ;;       ;;        ;;;;;            ;;;    ;;            ;;    ;;;       ;;;
     ;;;         ;;;;;;;;;;;;;       ;;  ;;           ;;;    ;;            ;;    ;;;       ;;;
     ;;;        ;;           ;;      ;;   ;;          ;;;     ;;          ;;     ;;;
     ;;;       ;;             ;;     ;;    ;;         ;;;       ;;      ;;       ;;;       ;;;
    ;;;;;     ;;               ;;    ;;     ;;       ;;;;;        ;;;;;;        ;;;;;      ;;;
    //rp++
     ;;    ;;;   ;; ;;;;              
     ;;  ;;      ;;;    ;;            
     ;; ;;       ;;       ;;          ;;               ;;
     ;;;;        ;;        ;;         ;;               ;;
     ;;;         ;;;      ;;          ;;               ;;
     ;;          ;; ;    ;;      ;;;;;;;;;;;;     ;;;;;;;;;;;;
     ;;          ;;  ;;;              ;;               ;;
     ;;          ;;                   ;;               ;;
     ;;          ;;                   ;;               ;;
     ;;          ;;
}

