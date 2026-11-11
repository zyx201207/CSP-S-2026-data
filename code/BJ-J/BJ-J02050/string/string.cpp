#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 +10;
int n;
struct srt{
    long long nm;
    char zf;
}sr[N];
long long sum;
long long cnt = 0;
long long ct;
long long mid;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin >> sr[i].nm >> sr[i].zf;
        sum += sr[i].nm;
    }
    if(sum % 2 == 0){

        mid = sum/2;
        int sid;
        bool b = 0;
        for(int i = 1;i<=n;i++){
            ct += sr[i].nm;
            if(ct == mid){
                sid = i;
                break;
            }

            if(ct > mid){
                if(sr[i].nm - (ct - mid) * 2 >= 0) sr[i].nm -= ct - mid * 2;
                else {
                    sr[i].nm -= (ct - mid) * 2;
                    sr[i].nm = -sr[i].nm;
                    b = 1;
                }
                sid = i;
                break;
            }
        }
        int j,i;
        if(b){
            j = sid + 1;
            i = sid;
        }else{
            i = sid - 1 ;
            j = sid ;
        }
        for(int i = sid;i>0,j<n+1;){
            if(sr[i].zf != sr[j].zf){
                if(sr[i].nm >= sr[j].nm){
                    sr[i].nm -= sr[j].nm;
                    cnt += sr[j].nm;
                    j++;
                }else{
                    sr[j].nm -= sr[i].nm;
                    cnt += sr[i].nm;
                    i--;
                }
            }else{
                if(sr[i].nm >= sr[j].nm){
                    sr[i].nm -= sr[j].nm;
                    j++;
                }else{
                    sr[j].nm -= sr[i].nm;
                    i--;
                }
            }
        }
        cout << cnt;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }else{

        mid = (sum+1)/2;
        int ct = 0;
        int sid;
        bool b = 0;
        for(int i = 1;i<=n;i++){
            ct += sr[i].nm;
            if(ct == mid){
                sid = i;
                sr[i].nm --;
                break;
            }

            if(ct > mid){
                if(sr[i].nm - (ct-mid) -1 > (ct-mid)){
                    sr[i].nm -= 1 + 2 * (ct-mid);
                }else{
                    b = 1;
                    sr[i].nm = (ct-mid) - (sr[i].nm - (ct-mid) - 1);
                }
                sid = i;
                break;
            }
        }
        int j,i;
        if(b){
            j = sid;
            i = sid - 1;
        }else{
            i = sid ;
            j = sid + 1;
        }
        for(;i>0,j<n+1;){
            if(sr[i].zf != sr[j].zf){
                if(sr[i].nm >= sr[j].nm){
                    sr[i].nm -= sr[j].nm;
                    cnt += sr[j].nm;
                    j++;
                }else{
                    sr[j].nm -= sr[i].nm;
                    cnt += sr[i].nm;
                    i--;
                }
            }else{
                if(sr[i].nm >= sr[j].nm){
                    sr[i].nm -= sr[j].nm;
                    j++;
                }else{
                    sr[j].nm -= sr[i].nm;
                    i--;
                }
            }
        }
        cout << cnt;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
