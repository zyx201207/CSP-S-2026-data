#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;
    long long si[200005];
    char sc[200005];

    for(int i=0; i<n; i++) cin >> si[i] >> sc[i];
    long long cnt=0;
    int r=n-1, l=0;
    while(r > l){
        if(sc[l] != sc[r]){
            if(si[l] > si[r]) {cnt += si[r]; si[l] -= si[r]; r--;}
            else if(si[l] == si[r]) {cnt += si[r]; l++; r--;}
            else {cnt += si[l]; si[r] -= si[l]; l++;}
        } else {
            if(si[l] > si[r]) {si[l] -= si[r]; r--;}
            else if(si[l] == si[r]) {l++; r--;}
            else {si[r] -= si[l]; l++;}
        }
    }

    if(n%2==1 && si[n/2] > 1 && sc[n/2] != sc[n/2-1]) cnt += si[n/2]-1;
    cout << cnt << endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}

