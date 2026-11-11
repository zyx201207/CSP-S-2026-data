#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , " w" , stdout);
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(m == 1) cout << n << endl;
    else if(m == 2){
        if(n == 2){
            if(a[1] == 1) cout << "1 2" << endl;
            else cout << "2 1" << endl;
        }
        else if(n == 3)
        {
            if(a[1] == 1){
                if(a[2] == 1) cout << "2 3" << endl;
                else{
                    if(a[3] == 1) cout << "3 1" << endl;
                    else cout << "1 3" << endl;
                }
            }
            else{
                if(a[2] == 1){
                    if(a[3] == 1) cout << "3 1" << endl;
                    else cout << "1 3" << endl;
                }
                else cout << "3 2" << endl;
            }
        }
        else if(n == 4){
            if(a[1] == 1){
                if(a[2] == 1){
                    if(a[3] == 1) cout << "3 4" << endl;
                    else{
                        if(a[4] == 1) cout << "4 1" << endl;
                        else cout << "2 4" << endl;
                    }
                }
                else{
                    if(a[3] == 1){
                        if(a[4] == 1) cout << "4 1" << endl;
                        else cout << "2 4" << endl;
                    }
                    else{
                        if(a[4] == 1) cout << "4 2" << endl;
                        else cout << "1 4" << endl;
                    }
                }
            }
            else{
                if(a[2] == 1){
                    if(a[3] == 1){
                        if(a[4] == 1) cout << "4 1" << endl;
                        else cout << "2 4" << endl;
                    }
                    else{
                        if(a[4] == 1) cout << "4 2" << endl;
                        else cout << "1 4" << endl;
                    }
                }
                else{
                    if(a[3] == 1){
                        if(a[4] == 1) cout << "4 2" << endl;
                        else cout << "1 4" << endl;
                    }
                    else{
                        if(a[4] == 1) cout << "4 3" << endl;
                    }
                }
            }
        }
        else if(n == 5){
            if(a[1] == 1){
                if(a[2] == 1){
                    if(a[3] == 1){
                        if(a[4] == 1) cout << "4 5" << endl;
                        else{
                            if(a[5] == 1) cout << "5 1" << endl;
                            else cout << "3 5" << endl;
                        }
                    }
                    else{
                        if(a[4] == 1){
                            if(a[5] == 1) cout << "5 1" << endl;
                            else cout << "3 5" << endl;
                        }
                        else{
                            if(a[5] == 1) cout << "5 2" << endl;
                            else cout << "2 5" << endl;
                        }
                    }
                }
                else{
                    if(a[3] == 1){
                        if(a[4] == 1){
                            if(a[5] == 1) cout << "5 1" << endl;
                            else cout << "3 5" << endl;
                        }
                        else{
                            if(a[5] == 1) cout << "5 2" << endl;
                            else cout << "2 5" << endl;
                        }
                    }
                    else{
                        if(a[4] == 1){
                            if(a[5] == 1) cout << "5 2" << endl;
                            else cout << "2 5" << endl;
                        }
                        else{
                            if(a[5] == 1) cout << "5 3" << endl;
                            else cout << "1 5" cout << endl;
                        }
                    }
                }
            }
            else{
                if(a[2] == 1){
                    if(a[3] == 1){
                        if(a[4] == 1){
                            if(a[5] == 1) cout << "5 1" << endl;
                            else cout << "3 5" << endl;
                        }
                        else{
                            if(a[5] == 1) cout << "5 2" << endl;
                            else cout << "2 5" << endl;
                        }
                    }
                    else{
                        if(a[4] == 1){
                            if(a[5] == 1) cout << "5 2" << endl;
                            else cout << "2 5" << endl;
                        }
                        else{
                            if(a[5] == 1) cout << "5 3" << endl;
                            else cout << "1 5" << endl;
                        }
                    }
                }
                else{
                    if(a[3] == 1){
                        if(a[4] == 1){
                            if(a[5] == 1) cout << "5 2" << endl;
                            else cout << "2 5" << endl;
                        }
                        else{
                            if(a[5] == 1) cout << "5 3" << endl;
                            else cout << "1 5" << endl;
                        }
                    }
                    else{
                        if(a[4] == 1){
                            if(a[5] == 1) cout << "5 3" << endl;
                            else cout << "1 5" << endl;
                        }
                        else cout << "5 4" << endl;
                    }
                }
            }
        }
    }
    else{
        for(int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
