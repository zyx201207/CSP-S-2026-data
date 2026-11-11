#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> inp;
vector<int> num[32];
int ans;
void save(){
    for(int i:inp){
        int j=0,x=i;
        while(x){
            if(x%2){
                num[j].push_back(i);
            }
            j++;
            x/=2;
        }
    }
    inp.clear();
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    inp.resize(n);
    for(int i=0;i<n;i++){
        cin >> inp[i];
    }
    save();
    /*
    for(int i=0;i<30;i++){
        for(int j:num[i]){
            cout << j << ' ';
        }
        cout << endl;
    }*/


    for(int pos=30;pos>=0;pos--){

        if(num[pos].size()<m){
            continue;
        }
        ans += (1<<pos);
        inp= move(num[pos]);
        for(int &i:inp){
            i &= ((1<<pos)- 1);
            //cout << i << ' ';
        }
        //cout << endl;

        for(int i=0;i<31;i++){
            /*
            for(int i:num[pos]){
                cout << i;
            }
            cout << endl;*/
            num[i].clear();
        }


        save();

    }

    cout << ans;

    cout << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}



