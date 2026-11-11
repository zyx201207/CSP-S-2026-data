#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    cin >> n >> m;
    int a[0];

    int only = 0;
    int sameAdd = 0;
    int all =0;
    int nm = 0;
    int les = m;
    int le[0];
    int lele=0;

    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int z = 0;z < n;z++){
        nm = a[z];
        for(int one = 0;one < n;one++){
            if(nm == a[one]){
                only++;
            }
            else{
                break;
            }
        }
        only--;
        for(int i = 0;i<n;i++){
            int adm = 0;
            for(int un = 0;un<n;un++){
                if(a[un]+les>=a[un+1]){
                    adm++;
                    les = a[un] + les - a[un+1];
                    if(les<0) break;
                    if(a[un+1]+les>=a[un+2]){
                        if((int)(les+a[un]+a[un+1]+a[un+2]%3)>=0){
                            adm++;
                        }
                    }
                }
            }
            sameAdd = adm;
        }
        all = sameAdd+only;
        le[z]=all;

    }

    for(int z = 0;z<n;z++){
        if(le[z]<le[z+1]){
            break;
        }
        if(le[z]>=le[z+1]){
            lele = z;
        }
    }
    cout<<le[lele];
    return 0;
}
