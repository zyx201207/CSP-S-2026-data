#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,sum,a[200001],t[200001];
long long lt,rt,l1,l2;
char s[200001];
string s0="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];cin>>s[i];
        t[i]=a[i]+t[i-1];
        sum+=a[i];
    }if(sum<=1000000000){
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i];j++){
                s0+=s[i];
            }
        }
        int lt=0,rt=sum-1;
        while(lt<=rt){
            if(s0[lt]!=s0[rt])ans++;
            lt++,rt--;
        }cout<<ans;
    }else{
        lt=0,rt=sum-1,l1=0,l2=n-1;
    while(lt<=rt&&rt>=(sum+1)/2&&lt<=sum/2-1){
        if(lt+min(a[l1],a[l2])<=sum/2-1 && rt-min(a[l1],a[l2])>=(sum+1)/2)
        lt+=min(a[l1],a[l2]),
        rt-=min(a[l1],a[l2]);
        if(s[l1]!=s[l2])ans+=min(a[l1],a[l2]);
        if(a[l1]>a[l2]){
            l2--;
            a[l1]-=a[l2+1];
        }else if(a[l1]<a[l2]){
            l1++;
            a[l2]-=a[l1-1];
        }else{
            l1++,l2--;
        }
    }ans/=2;
    while(lt<=sum/2){
        if(lt>t[l1])l1++;
        if(rt<t[l2-1])l2--;
        if(s[l2]!=s[l1])lt++,rt--,ans++;
    }
    cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
}

