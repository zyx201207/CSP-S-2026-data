#include<bits/stdc++.h>
using namespace std;
//long long a[200005];
//char c[200005];
struct zm{
    long long a;
    char c;
};
zm s[200005];
bool cmp(zm a,zm b){
    return a.a>b.a;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;//zongchang
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        sum+=s[i].a;
    }
    //sort(s+1,s+n+1,cmp);
    long long cz=0;//caozuocishu action times
    long long mid;
    if(sum%2==0){
        mid=sum/2;
        long long tot=0;
        int h=1,t=n;
        /*for(;h<t;){
            int a1=s[h].a,a2=s[t].a;
            char c1=s[h].c,c2=s[t].c;
            int num=abs(a1-a2);
            a1-=num;
            a2-=num;
            if(c1==c2){tot+=num;h++;t--;}
            else{
                tot+=num;
                cz+=num;
                if(tot>=mid){
                    cz=cz-(tot-mid);
                    break;
                }
                if(a1==0)h++;
                else t--;
            }
            if(tot>=mid)break;
        }*/
        while(tot<mid){
            if(s[h].c==s[t].c){
                tot+=min(s[h].a,s[t].a);
                s[h].a-=min(s[h].a,s[t].a);
                s[t].a-=min(s[h].a,s[t].a);
                continue;
            }
            if(s[h].a<s[t].a&&s[h].a!=0&&s[t].a!=0){
                s[t].a-=s[h].a;
                tot+=s[h].a;
                cz+=s[h].a;
                //cout<<1111111111111<<endl;
                h++;
                continue;
            }
            else if(s[h].a==0){
                h++;
            }
            else if(s[t].a==0){
                t--;
            }
            else{
                s[h].a-=s[t].a;
                tot+=s[t].a;
                cz+=s[t].a;
                //cout<<6666666666<<endl;
                t--;
            }
        }
    }
    else{
        mid=sum/2+1;
        int tot=0;
        int h=1,t=n;
        while(tot<mid){
            if(s[h].c==s[t].c){
                tot+=min(s[h].a,s[t].a);
                s[h].a-=min(s[h].a,s[t].a);
                s[t].a-=min(s[h].a,s[t].a);
                continue;
            }
            if(s[h].a<s[t].a&&s[h].a!=0&&s[t].a!=0){
                s[t].a-=s[h].a;
                tot+=s[h].a;
                cz+=s[h].a;
                //cout<<1111111111111<<endl;
                h++;
                continue;
            }
            else if(s[h].a==0){
                h++;
            }
            else if(s[t].a==0){
                t--;
            }
            else{
                s[h].a-=s[t].a;
                tot+=s[t].a;
                cz+=s[t].a;
                //cout<<6666666666<<endl;
                t--;
            }
        }
    }

    cout<<cz;
    /*
    zhaoshuliangzuiduode
    jianqushuliangzuishaode
    jiangliangbiangaichengyiyangd
    aaccccde
    aafcddef
    aaggeebbaa
    */
    return 0;
}
