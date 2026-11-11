#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int math,must,mustc; //1
    int cnt = 0;
    cin>>math>>must;
    int s[50] = {0};
    int shuju[20];
    int c[3] = {0};
    mustc = must; //8

    int velue = 0;
    for(int j = 0;j<=math;j++){
        if (j == 1) continue;

        cin>>s[j];
        int lc = 0;
        int velue1 = 0;



        c[0] = s[j-1];
        c[1] = s[j];
        lc = c[0] - c[1];



        while(s[j-1] != s[j] && mustc != 0){ //9
            if(lc<0){
                c[0]++;
                c[1]--;
                mustc --; //2
                continue;

            }
            else if (lc>0 && mustc != 0){ //10
                c[0]--;
                c[1]++;
                mustc --; //3
                continue;
            }
            else {
                break;
            }



        }

        velue1 = c[0]+=c[1];
        if(c[0] == c[1]&&mustc == 0&&c[0]==s[j]){
            velue1 = 0;
            mustc = must; //5
            continue;
        }



        cnt++;
        must = mustc; //7


    }

    cout<<cnt;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
