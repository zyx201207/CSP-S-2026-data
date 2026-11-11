#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string last = "";
    cin >> n;
    long long time;
    string word;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> time >> word;
        for (long long j = 1; j <= time; j++){
            last = last+word;
        }
    }
    long long cd = last.size();
    if (cd%2==0){
        for (long long i=0; i<=(cd-1)/2; i++){
            if (last[i] != last[cd-1-i]) ans++;
        }
    }
    else{
        for (long long i=0; i<=(cd-2)/2; i++){
            if (last[i] != last[cd-1-i]) ans++;
        }
    }

    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
